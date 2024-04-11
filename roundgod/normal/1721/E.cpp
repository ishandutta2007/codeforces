#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 1000015
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,a[MAXN];
vector<vector<int> > aut;
vector<int> pi;
string s,t;
int q;
vector<int> prefix_function(string s) {
    int n = (int)s.length();
    vector<int> pi(n);
    for(int i=1;i<n;i++) 
    {
        int j=pi[i-1];
        while (j>0&&s[i]!=s[j]) j=pi[j - 1];
        if (s[i]==s[j]) j++;
        pi[i]=j;
    }
    return pi;
}
int compute_automaton(string s, vector<vector<int>>& aut) {
  int n = s.size();
  bool same=true;
  for(int i=1;i<n;i++) if(s[i]!=s[i-1]) same=false;
  aut.assign(n, vector<int>(26));
  for (int i = 0; i < n; i++) {
    for (int c = 0; c < 26; c++) {
      if (i > 0 && 'a' + c != s[i])
        aut[i][c] = aut[pi[i - 1]][c];
      else
        aut[i][c] = i + ('a' + c == s[i]);
    }
  }
  return pi[n-1];
}
int main()
{
    cin>>s;
    int n=(int)s.size(); 
    pi=prefix_function(s);
    int fail=compute_automaton(s,aut);
    cin>>q;
    while(q--)
    {
        cin>>t;
        int m=(int)t.size();
        int tmp=fail;
        for(int i=n;i<n+m;i++)
        {
            aut.push_back(vector<int>(26));
            for(int j=0;j<26;j++)
            {
                if(j!=t[i-n]-'a') aut[i][j]=aut[pi[i-1]][j];
                else aut[i][j]=i+('a'+j==t[i-n]);
            }
            pi.push_back(aut[pi[i-1]][t[i-n]-'a']);
            printf("%d ",pi[i]);
        }
        for(int i=0;i<m;i++) {aut.pop_back(); pi.pop_back();}
        puts("");
    }
    return 0;
}