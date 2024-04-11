#include <cstdio>
#include <stack>

const int inf = 999999999;

int N;
int a[100010]; // ids
int b[100010]; // closest larger element to the right
int c[100010]; // length of longest chain ending at each element
bool d[100010]; // whether this is the start of a new section

int main()
{
    scanf("%d", &N);
    for (int i = 0; i < N; i++) scanf("%d", &a[i]);
    a[N] = inf;

    std::stack<int> s;
    s.push(N);
    for (int i = N-1; i >= 0; i--) {
        while (a[i] > a[s.top()]) s.pop();
        b[i] = s.top();
        s.push(i);
    }
    
    int cur = 0;
    while (cur < N) {
        d[cur] = true;
        cur = b[cur];
    }

    int ans = 0;
    for (int i = 0; i < N; i++) {
        if (d[i]) {
            ans = std::max(ans, c[i]);
            c[i] = 0;
        }
        else c[b[i]] = std::max(c[b[i]], c[i]+1);
    }
    ans = std::max(ans, c[N]);
    
    printf("%d\n", ans);
}