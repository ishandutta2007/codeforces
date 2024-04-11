#include <bits/stdc++.h>
#define sz(x) ((int)((x).size()))
typedef long long ll;

int N;
int a[200005];
int b[200005];

struct S {
    int i; S(int ii) : i(ii) { }
    bool operator<(const S &s) const { return a[i]+i > a[s.i]+s.i; }
};

int main()
{
    scanf("%d", &N);
    for (int i = 0; i < N; i++) scanf("%d", &a[i]);
    std::priority_queue<S> q;
    for (int i = 0; i < N; i++) q.push(S(i));
    b[0] = q.top().i; q.pop();
    for (int i = 1; i < N; i++) {
        b[i] = q.top().i; q.pop();
        if (a[b[i-1]]+b[i-1] > a[b[i]]+b[i] - 1) { printf(":(\n"); return 0; }
    }
    for (int i = 0; i < N; i++) printf("%d%c", a[b[i]]+b[i]-i, " \n"[i == N-1]);
}