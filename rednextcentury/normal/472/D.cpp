#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define pi pair<int, int>
#define pii pair<int, pi>
#define F first
#define S second
#define pb push_back
#define PI acos(-1.0)
using namespace std;
ll const N = 2020;
ll n, a[N][N], Seg[5*N], sum;
ll First[N], Height[N], Weight[N];
vector<ll> Eueler;
vector<vector<int>> Tree;
priority_queue<pii, vector<pii>, greater<pii>> q;
bool vis[N], bol[N];

void DFS(int Node, int H, long long W)
{
    vis[Node] = true;
    Weight[Node] = W;
    First[Node] = Eueler.size();
    Height[Node] = H;
    Eueler.pb(Node);

    for (auto i : Tree[Node]) if (!vis[i]){
            DFS(i, H + 1, W + a[Node][i]);
            Eueler.pb(Node);
        }
}

void Build(int Node = 1, int L = 0, int R = Eueler.size() - 1)
{
    if (L == R){
        Seg[Node] = Eueler[L];
        return;
    }

    int Middle = L + R >> 1;
    Build(Node << 1, L, Middle);
    Build(Node << 1 | 1, Middle + 1, R);

    int Left = Seg[Node << 1];
    int Right = Seg[Node << 1 | 1];
    Seg[Node] = (Height[Left] < Height[Right] ? Left : Right);
}

int Query(int i, int j, int Node = 1, int L = 0, int R = Eueler.size() - 1)
{
    if (L > j || R < i)
        return -1;

    if (L >= i && R <= j)
        return Seg[Node];

    int Middle = L + R >> 1;
    int Left = Query(i, j, Node << 1, L, Middle);
    int Right = Query(i, j, Node << 1 | 1, Middle + 1, R);

    if (Left == -1) return Right;
    if (Right == -1) return Left;
    return (Height[Left] < Height[Right] ? Left : Right);
}

int Check(int i, int j)
{
    if (First[i]>First[j])swap(i,j);
    return Weight[i] + Weight[j] - 2 * Weight[Query(First[i], First[j])];
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++){
            cin >> a[i][j];
            sum += a[i][j];
        }
    if (!sum && n > 1) return cout << "NO\n", 0;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if ((i == j && a[i][j]) || a[i][j] != a[j][i])
                return cout << "NO\n", 0;

    Tree.resize(n+1);
    Tree.clear();
    for (int i = 2; i <= n; i++)
        q.push({a[1][i], {1, i}});
    bol[1] = true;

    while(!q.empty()){
        int s = q.top().S.F;
        int to = q.top().S.S;

        q.pop();
        if (bol[to])
            continue;

        Tree[s].pb(to);
        Tree[to].pb(s);
        bol[to] = true;
        for (int i = 1; i <= n; i++) if (!bol[i] && i != to){
                q.push({a[to][i], {to,i}});
            }
    }

    // for (int i = 1; i <= n; i++, cout << '\n')
    // 	for (auto j : Tree[i])
    // 		cout << j << ' ';

    DFS(1, 0, 0);
    Build();
    for (int i = 1; i <= n; i++)
        for (int j = i + 1; j <= n; j++)
            if (Check(i, j) != a[i][j])
                return cout << "NO\n", 0;

    cout << "YES\n";
    return 0;
}