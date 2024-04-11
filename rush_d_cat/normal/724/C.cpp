#include <vector>
#include <cmath>
#include <map>
#include <set>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
typedef long long ll;
const int ADD = 200000;
typedef pair<ll, ll> P;
map<P, ll> mp;
vector<P> vec[400005][3];
ll n, m, K;
ll used[400005][3];
ll x_[200000 + 10], y_[200000 + 10];
int main()
{
    cin >> n >> m >> K;
    int i;
    for(i = 1; i <= K; i++)
    {
        P p;scanf("%I64d %I64d", &p.first, &p.second);
        x_[i] = p.first;
        y_[i] = p.second;
        vec[p.second-p.first+ADD][2].push_back(p);
        vec[p.second+p.first+ADD][1].push_back(p);
        mp[p] = -1;
    }
    ll k = 2, b = 0 ,t = 0;
    ll cx = 0, cy = 0;
    
    while(true)
    {
        used[b+ADD][k] = 1;
        int sz = vec[b+ADD][k].size();
        for(i = 0; i < sz; i++)
        {
            P p = vec[b+ADD][k][i];
            if(mp[p] == -1)
            {
                mp[p] = t + abs(p.first - cx);
            }
        }
        vec[b+ADD][k].clear();
        
        if(cx == 0)
        {
            if(k == 2)
            {
                if(n > m - cy)
                {
                    cx = m - cy;
                    cy = m;
                } else {
                    cx = n;
                    cy = cy + n;
                }
            } else {
                if(cy > n)
                {
                    cx = n;
                    cy = cy - n;
                } else {
                    cx = cy;
                    cy = 0;
                }
            }
            t += cx;
        }
        else
            if(cx == n)
            {
                if(k == 2)
                {
                    if(n > cy)
                    {
                        cx = n - cy;
                        cy = 0;
                    } else {
                        cy = cy - n;
                        cx = 0;
                    }
                } else {
                    if(m - cy < n)
                    {
                        cx = n - (m - cy);
                        cy = m;
                    } else {
                        cx = 0;
                        cy = cy + n;
                    }
                }
                t += n - cx;
            }
            else
                if(cy == 0)
                {
                    if(k == 2)
                    {
                        if(m > n - cx)
                        {
                            cy = n - cx;
                            cx = n;
                        } else {
                            cy = m;
                            cx = cx + m;
                        }
                    } else {
                        if(cx < m)
                        {
                            cy = cx;
                            cx = 0;
                        } else {
                            cy = m;
                            cx = cx - m;
                        }
                    }
                    t += cy;
                } else
                    if(cy == m)
                    {
                        if(k == 2)
                        {
                            if(cx < m)
                            {
                                cy = cy - cx;
                                cx = 0;
                            } else {
                                cy = 0;
                                cx = cx - m;
                            }
                        } else {
                            if(n - cx < m)
                            {
                                cy = m - (n - cx);
                                cx = n;
                            } else {
                                cy = 0;
                                cx = cx + m;
                            }
                        }
                        t += m - cy;
                    }
        k = 3 - k;
        if(k == 2) b = cy - cx;
        if(k == 1) b = cy + cx;
        if((cx == 0 || cx == n) && (cy == 0 || cy == m)) break;
    }
    
    for(i = 1; i <= K; i++)
    {
        P p;
        p.first = x_[i];
        p.second = y_[i];
        printf("%I64d\n", mp[p]);
    }
}