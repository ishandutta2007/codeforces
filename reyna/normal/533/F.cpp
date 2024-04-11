//In the name of God
#include <bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define Rof(i,a,b) for(int (i)=(a);(i) >= (b); --(i))
#define mkp make_pair
#define XX first
#define YY second
#define pb push_back
const int Maxn = 2e5 + 9;
typedef long long ll;
const ll x = 37;
const ll Mod = (ll)1e9 + 9;
ll tval[26],val[26],len[26],tlen[26];
int Que[Maxn][26],bg[26],ed[26];
int mark[Maxn];
vector<ll> s1,s2;
char S[Maxn],P[Maxn];
ll invx;
ll sum[Maxn];
int n,m;
ll pw(ll a,ll b){
    return b?(pw((a * a) % Mod,b >> 1) * (b & 1?a:1))%Mod:1;
}
void add(int ch,ll *va,ll *le){
    ch -= 'a';
    va[ch] *= x;
    va[ch] += m;
    va[ch] %= Mod;
    le[ch]++;
}
void remove(int ch,ll *va,ll *le){
    ch -= 'a';
    va[ch] -= pw(x,le[ch] - 1);
    va[ch] %= Mod;
    va[ch] += Mod;
    va[ch] %= Mod;
    le[ch]--;
}
void upd(int ch,ll *va,ll *le){
    ch -= 'a';
    if(le[ch]){
        va[ch] -= sum[le[ch] - 1];
        va[ch] %= Mod;
        va[ch] += Mod;
        va[ch] %= Mod;
    }
}
bool cmp(int j){
//  s1.clear(),s2.clear();
//  For(i,0,26)
//      s1.push_back(val[i]);
//  For(i,0,26)
//      s2.push_back(tval[i]);
//  sort(s1.begin(),s1.end());
//  sort(s2.begin(),s2.end());
//  For(i,0,26)
//      if(s1[i] != s2[i]){
//          return 0;
//      }
//  return 1;
    For(i,0,26)
        if(ed[i] - bg[i])
            if(tval[P[Que[bg[i]][i] - j]-'a'] != val[S[Que[bg[i]][i]]-'a'] || val[P[Que[bg[i]][i] - j]-'a'] != tval[S[Que[bg[i]][i]]-'a'])
                return 0;
    return 1;
}
int main(){
    sum[0] = 1;
    For(i,1,Maxn)
        sum[i] = (sum[i-1] + pw(x,i)) % Mod;
    scanf("%d%d",&n,&m);
    scanf("%s",&S);
    scanf("%s",&P);
    For(i,0,m){
        tval[P[i] - 'a'] *= x;
        tval[P[i] - 'a'] += i+1;
        tval[P[i] - 'a'] %= Mod; 
    }
    int ans = 0;
    For(i,0,m){
        Que[ed[S[i] - 'a']++][S[i] - 'a'] = i;
        val[S[i] - 'a'] *= x;
        val[S[i] - 'a'] += i+1;
        val[S[i] - 'a'] %= Mod;
        len[S[i] - 'a']++; 
    }
    if(cmp(0))
        mark[0] = 1;
    ans += mark[0];
    For(i,1,n-m+1){
        For(j,0,26)
            if(ed[j] > bg[j] && Que[bg[j]][j] < i)
                bg[j]++;
        remove(S[i-1],val,len);
        For(j,0,26)
            upd(j+'a',val,len);
        add(S[i+m-1],val,len);
        Que[ed[S[i+m-1] - 'a']++][S[i+m-1]-'a'] = i+m-1;
        if(cmp(i))
            mark[i] = 1;
        ans += mark[i];
//      cerr << i << ' ' <<  val[0] << ' ' << tval[0] << endl;
    }
    printf("%d\n",ans);
    For(i,0,Maxn)
        if(mark[i])
            printf("%d ",i+1);
    return 0;
    
}