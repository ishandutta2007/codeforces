#include<bits/stdc++.h>
using namespace std;
int adj[301001][26];
int cnt[301001];
string s;
long long L[1000000];
long long R[1000000];
const int SQR = 377;
struct Trie
{
    int V=0;
    void add(string x)
    {
        int v=0;
        for (int i=0;i<x.size();i++)
        {
            if (adj[v][x[i]-'a']==0)
                adj[v][x[i]-'a']=++V;
            v=adj[v][x[i]-'a'];
        }
        cnt[v]++;
    }
    int query(int i)
    {
        int v=0;
        int num=0;
        for (int b=0;b<SQR;b++)
        {
            if (i==s.size())return num;
            if (adj[v][s[i]-'a']==0)return num;
            v=adj[v][s[i]-'a'];
            num+=cnt[v];
            R[i]+=cnt[v];
            i++;
        }
        return num;
    }
};
char inp[1000000];
string st[1000000];
#define fst first
#define snd second
#define all(c) ((c).begin()), ((c).end())

struct knuth_morris_pratt {
  int m;
  string p;
  vector<int> fail;
  knuth_morris_pratt(string p) : p(p), m(p.size()) {
    fail.resize(m+1, -1);
    for (int i = 1, j = -1; i <= m; ++i) {
      while (j >= 0 && p[j] != p[i-1]) j = fail[j];
      fail[i] = ++j;
    }
  }
  void match() {
    int n = s.size();
    vector<int> occur;
    for (int i = 0, k = 0; i < n; ++i) {
      while (k >= 0 && s[i] != p[k]) k = fail[k];
      if (++k == m) {
        /* match at s[i-m+1 ... i] */
        L[i-m+1]++;
        R[i]++;
      }
    }
  }
};
int main()
{
    int n;
    scanf("%s",inp);
    s=inp;
    scanf("%d",&n);
    Trie trie;
    for (int i=0;i<n;i++)
    {

        scanf("%s",inp);
        st[i]=inp;
        if (st[i].size()<=SQR)
            trie.add(st[i]);
        else
        {
            knuth_morris_pratt kmp(st[i]);
            kmp.match();
        }
    }
    for (int i=0;i<s.size();i++)
        L[i]+=trie.query(i);

    long long ret=0;
    for (int i=0;i<s.size();i++)
    {
        ret+=R[i]*L[i+1];
    }
    cout<<ret<<endl;

}