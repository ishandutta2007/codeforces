#include <cstdio>
#include <map>
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

typedef pair<int, int> pii;

const int MAXN = 10000;

pii ar[MAXN];
int scores[MAXN];
int cursc[MAXN];
int first[MAXN];
int N;
vector<string> names;
map<string, int> mymap;
int k = 0;
int get(string s) {
    int &ret = mymap[s];
    if (ret) return ret - 1;
    names.push_back(s);
    ret = k++;
    return ret++;
}
char buf[1000];
int main() {
    scanf("%d", &N);
    for(int i = 0; i < N; ++i) {
        int tmp;
        scanf("%s %d", buf, &tmp);
        string s(buf);
        int guy = get(s);
        ar[i] = pii(guy, tmp);
    }
    for(int i = 0; i < N; ++i) {
        scores[ar[i].first] += ar[i].second;
    }
    for(int i = 0; i < N; ++i) {
        cursc[ar[i].first] += ar[i].second;
        if (!first[ar[i].first] && cursc[ar[i].first] >= 
        scores[ar[i].first]) {
            first[ar[i].first] = i + 1;
        }
    }
    int best = 1;
    for(int i = 0; i < k; ++i) {
        if (scores[i] > scores[best] || (scores[i] == scores[best] && first[i] < first[best])) {
            best = i;
        }
    }
    printf("%s\n", names[best].c_str());
    return 0;
}