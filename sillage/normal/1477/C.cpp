#include<bits/stdc++.h>
using namespace std;
const int maxn = 5010;
struct point{
    int x, y;
    point operator - (const point & b)const{
        return point{x - b.x, y - b.y};
    }
    long long operator * (const point & b)const{
        return 1ll * x * b.x + 1ll * y * b.y;
    }
}p[maxn];
int t[maxn];
int main()
{
    int n;
    cin >> n;
	for (int i = 1; i <= n; i++) scanf("%d%d", &p[i].x, &p[i].y), t[i] = i;
    bool flag = 1;
	for (int i = 1; i <= n; i++){
        flag = 0;
        for (int j = n; j >= 3; j--)
		    if ( ((p[t[j - 2]] - p[t[j - 1]]) * (p[t[j]] - p[t[j - 1]])) <= 0)	swap(t[j - 1], t[j]), flag = 1;
        if (!flag) break;
    }
    if (!flag)
        for (int i = 1; i <= n; i++) printf("%d ", t[i]);
	else puts("-1");
}