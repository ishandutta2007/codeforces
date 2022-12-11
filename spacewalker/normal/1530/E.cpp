#include <bits/stdc++.h>

using namespace std;
constexpr int NMAX = 100010;

void solve() {
    static char s[NMAX];
    scanf("%s", s);
    int n = strlen(s);
    map<char, int> occs;
    for (int i = 0; s[i]; ++i) ++occs[s[i]];
    if (occs.size() == 1) {
        printf("%s\n", s);
    } else if (occs.size() == n) {
        vector<char> vs;
        for (int i = 0; i < n; ++i) vs.push_back(s[i]);
        sort(begin(vs), end(vs));
        for (char c : vs) printf("%c", c);
        printf("\n");
    } else {
        // here min f(t) always 1
        vector<char> posfirsts;
        vector<int> cts;
        for (auto [c, f] : occs) {
//            printf("string has %d %c\n", f, c);
            posfirsts.push_back(c);
            cts.push_back(f);
        }
        string bestStr = string(n, '~');
        int k = posfirsts.size();
        int pinakamalimit = distance(begin(cts), min_element(begin(cts), end(cts)));
        if (cts[pinakamalimit] == 1) {
            string cstr(n, '~');
            vector<int> ctsHere = cts;
            --ctsHere[pinakamalimit];
            cstr[0] = posfirsts[pinakamalimit];
            int cstrptr = 1;
            for (int x = 0; x < k; ++x) {
                for (int p = 0; p < ctsHere[x]; ++p) cstr[cstrptr++] = posfirsts[x];
            }
            printf("%s\n", cstr.c_str());
            return;
        }
        auto findViolator = [&] (string &cstr) {
            for (int i = 1; i + 1 < n; ++i) {
                if (cstr[i] == cstr[0] && cstr[i+1] == cstr[1]) return i;
            }
            return -1;
        };
        for (int i = 0; i < k; ++i) {
            for (int j = 0; j < k; ++j) {
//                printf("checking %c %c\n", posfirsts[i], posfirsts[j]);
                if (i == j) {
                /* checking same first char:
                *    fix first 2 chars, sort the rest
                *    let a range R be the range of our first char in the rest of the string
                *    if violates, then
                *      grow R to the right, then to the left
                *      until R has exactly twice the length
                *      then "interleave" the first char with the sorted ver of the rest of the chars
                */
                    string cstr(n, '~');
                    vector<int> ctsHere = cts;
                    if (ctsHere[i] < 2) continue;
                    ctsHere[i] -= 2;
                    cstr[0] = cstr[1] = posfirsts[j];
                    int cstrptr = 2;
                    for (int x = 0; x < k; ++x) {
                        for (int p = 0; p < ctsHere[x]; ++p) cstr[cstrptr++] = posfirsts[x];
                    }
//                    printf("starter %s\n", cstr.c_str());
                    int violatorIdx = findViolator(cstr);
                    if (violatorIdx != -1) {
                        int vst = violatorIdx, ved = violatorIdx;
                        if (vst == 1) vst = 2; // we'll manually deal with this case later
                        char vc = cstr[vst];
                        while (ved < n && cstr[vst] == cstr[ved]) ++ved;
                        int vlen = ved - vst;
//                        printf("!! violate range %d %d\n", vst, ved);
                        while (ved < n && ved - vst < 2 * vlen) ++ved;
                        while (vst > 1 && ved - vst < 2 * vlen) --vst;
//                        printf("!! violate range %d %d\n", vst, ved);
                        if (vst == 1) continue; // not enough characters here
                        string half1, half2;
                        for (int x = vst; x < ved; ++x) {
                            if (cstr[x] == vc) half2.push_back(cstr[x]);
                            else half1.push_back(cstr[x]);
                        }
//                        printf("!! halves %s %s\n", half1.c_str(), half2.c_str());
                        if ((half1 > half2 && vst > 2) && violatorIdx != 1) swap(half1, half2);
//                        printf("!! halves %s %s\n", half1.c_str(), half2.c_str());
                        // now we interleave
                        for (int x = vst; x < ved; ++x) {
                            cstr[x] = ((x - vst) % 2 == 0 ? half1 : half2)[(x - vst) / 2];
//                            printf("putting %c on %d\n", cstr[x], x);
                        }
                    }
//                    printf("result is %s\n", cstr.c_str());
                    bestStr = min(bestStr, cstr);
                } else {

                /* checking diff first char:
                *   fix first 2 chars, sort the rest
                *   if violates, then
                *      - if [ab].... aaabbbbccccc
                *          then transform to [ab].... aaacbbbbcccc
                *     -  if [ab].... aaabbbb$
                *          then transform to [ab].... bbbbaaa
                */
                    string cstr(n, '~');
                    vector<int> ctsHere = cts;
                    ctsHere[i]--; ctsHere[j]--;
                    cstr[0] = posfirsts[i]; cstr[1] = posfirsts[j];
                    int cstrptr = 2;
                    for (int x = 0; x < k; ++x) {
                        for (int p = 0; p < ctsHere[x]; ++p) cstr[cstrptr++] = posfirsts[x];
                    }
                    int violateIdx = findViolator(cstr);
                    if (violateIdx != -1) {
//                        printf("!! violator %d\n", violateIdx);
                        int frontEdge = violateIdx, backEdge = violateIdx + 1;
                        while (frontEdge > 1 && cstr[frontEdge] == cstr[violateIdx]) --frontEdge;
                        while (backEdge < n && cstr[backEdge] == cstr[violateIdx + 1]) ++backEdge;
//                        printf("!! vrange %d %d\n", frontEdge, backEdge);
                        if (backEdge < n) {
                            swap(cstr[violateIdx + 1], cstr[backEdge]);
                        } else {
//                            printf("full swap case\n");
                            int backLen = backEdge - (violateIdx + 1), frontLen = violateIdx - frontEdge;
                            for (int x = 0; x < backLen; ++x) cstr[frontEdge + 1 + x] = cstr[1];
                            for (int x = backLen; x < backLen + frontLen; ++x) cstr[frontEdge + 1 + x] = cstr[0];
                        }
                    }
                    bestStr = min(bestStr, cstr); 
                }
            }
        }
        printf("%s\n", bestStr.c_str());
    }        
}

int main() {
    int t; scanf("%d", &t);
    while (t--) solve();
}