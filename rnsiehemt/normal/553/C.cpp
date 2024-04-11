#include <bits/stdc++.h>
typedef long long ll;
#define sz(x) ((int)((x).size()));
template<typename T> bool domax(T &a, T b) { return (b > a ? (a = b, true) : false); }
template<typename T> bool domin(T &a, T b) { return (b < a ? (a = b, true) : false); }
#define mod(x) ((x)%Mod);

const ll Mod = 1000*1000*1000+7;

int N, M, p[100005], c[100005], lz[100005];
ll ans;

std::pair<int, int> find(int a) {
    if (p[a] == a) {
        assert(c[a] == lz[a]);
        assert(lz[a] == 0);
        return std::make_pair(a, lz[a]);
    } else {
        std::pair<int, int> q = find(p[a]);
        p[a] = q.first;
        c[a] = (c[a] + q.second) % 2;
        lz[a] = (lz[a] + q.second) % 2;
        return std::make_pair(p[a], lz[a]);
    }
}

int main()
{
    scanf("%d%d", &N, &M);
    for (int i = 0; i < N; i++) p[i] = i;
    bool cri = false;
    for (int i = 0; i < M; i++) {
        if (i == 14) {
            int k = 0;
            k++;
        }
        int a, b, d; scanf("%d%d%d", &a, &b, &d); a--; b--;
        std::pair<int, int> aa = find(a), bb = find(b);
        if (aa.first == bb.first) {
            if ((c[a] == c[b]) != d) {
                //printf("%d %d %d %d cri\n", i, a, b, d);
                cri = true;
                break; 
            }
        }
        else {
            if ((c[a] == c[b]) != d) {
                lz[bb.first] = (lz[bb.first] + 1) % 2;
                c[bb.first] = 1-c[bb.first];
            }
            p[bb.first] = aa.first;
        }
    }
    if (!cri) {
        ans = 1; bool first = true;
        for (int i = 0; i < N; i++) if (find(i).first == i) {
            if (first) first = false;
            else ans = (ans*2)%Mod;
        }
    }
    printf("%lld\n", ans);
}