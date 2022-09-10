#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ui unsigned int
#define inf 1000000007
#define INF 1000000000000000007LL
#define VI vector<int>
#define VPII vector<pair<int, int> >
#define VLL vector<ll>
#define PII pair<int, int>
#define st first
#define nd second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define endl '\n'
#define ALL(c) (c).begin(), (c).end()
using namespace std;

#define N 200007

int z, n, c = 1;

int l;

VI q;

int trie[30*N][2];

void wstaw(int a, int l)
{
      int s = 1;

      for(int i = l; i >= 0; --i)
      {
              if((a&(1<<i)))
              {
                      if(!trie[s][1])
                              trie[s][1] = ++c;

                      s = trie[s][1];
              }
              else
              {
                      if(!trie[s][0])
                              trie[s][0] = ++c;

                      s = trie[s][0];
              }
      }
}

int znajdz(int a, int l)
{
      int s = 1, d = 0;

      for(int i = l; i >= 0; --i)
      {
              if((a&(1<<i)))
              {
                      if(!trie[s][1])
                      {
                              d += (1<<i);
                              s = trie[s][0];
                      }
                      else
                              s = trie[s][1];
              }
              else
              {
                      if(!trie[s][0])
                      {
                              d += (1<<i);
                              s = trie[s][1];
                      }
                      else
                              s = trie[s][0];
              }
      }

      return d;
}

void czysc()
{
      for(int i = 1; i <= c; ++i)
      {
              trie[i][0] = trie[i][1] = 0;
      }

      c = 1;
}

ll f(int l, VI &v)
{
      if(l==0)
      {
              if(v.size()==1)
                      return 0;
              else
                      return 1;
      }

      VI v0;
      VI v1;

      for(auto it:v)
      {
              if((it&(1<<l)))
                      v1.pb(it);
              else
                      v0.pb(it);
      }

      ll res = 0;

      if(v1.size()>1)
              res += f(l-1, v1);

      if(v0.size()>1)
              res += f(l-1, v0);

      if(v1.empty() || v0.empty())
              return res;

      int o = 2*inf;

      for(auto it1:v1)
      {
              wstaw(it1, l);
      }

      for(auto it0:v0)
      {
              o = min(o, znajdz(it0, l));
      }

      czysc();

      return res+o;
}

void solve()
{
      q.clear();

      cin >> n;

      for(int i = 1; i <= n; ++i)
      {
              cin >> l;
              q.pb(l);
      }

      sort(ALL(q));
      q.erase(unique(ALL(q)), q.end());

      cout << f(29, q) << endl;
}

int32_t main()
{
      ios_base::sync_with_stdio(0);
      cin.tie(NULL);

      solve();

}