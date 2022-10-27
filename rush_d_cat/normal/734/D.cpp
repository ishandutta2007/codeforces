#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
typedef long long ll;
const int NICO = 500000+2;
ll n;
ll x, y;
struct node
{
    char name;
    ll d;
    node(char name_, ll d_){name=name_,d=d_;}
};
bool cmp(node a, node b)
{
    return a.d < b.d;
}
vector<node> vec[10];

int rush(ll x_, ll y_)
{
    if(x_ == x && y_ > y) return 1;
    if(x_ == x && y_ < y) return 2;
    if(y_ == y && x_ < x) return 3;
    if(y_ == y && x_ > x) return 4;
    ll dx = x_ - x;
    ll dy = y_ - y;
    if(dx > 0 && dy > 0 && dx == dy) return 5;
    if(dx < 0 && dy < 0 && dx == dy) return 6;
    if(dx < 0 && dy > 0 && dx == -dy)return 7;
    if(dx > 0 && dy < 0 && dx == -dy)return 8;
    return 0;
}
int main()
{
    ios::sync_with_stdio(false);
    cin >> n;
    cin >> x >> y;
    for(int i=1;i<=n;i++)   
    {
        char name;
        ll cx, cy;
        cin >> name >> cx >> cy;
        int sta = rush(cx, cy);
        if(sta == 0) continue;
        node tmp(name, max(abs(cx-x), abs(cy-y)));
        vec[sta].push_back(tmp);
    }
    bool ok = 0;
    for(int i=1;i<=4;i++)
    {
        if(vec[i].size() == 0) continue;
        sort(vec[i].begin(), vec[i].end(), cmp);
        if(vec[i][0].name != 'B') ok = 1;
    }
    for(int i=5;i<=8;i++)
    {
        if(vec[i].size() == 0) continue;
        sort(vec[i].begin(), vec[i].end(), cmp);
        if(vec[i][0].name != 'R') ok = 1;
    }
    if(ok) cout << "YES" << endl;
    else cout << "NO" << endl;
}