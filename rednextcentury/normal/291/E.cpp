#include <bits/stdc++.h>
using namespace std;
static const int N=(int)5e5+10, base=1337, m1=1e9+123, m2=1e9+321;
int n,len;
long long pref[N],need;
char t[N],c[N],s[N];
long long ans;
vector<int> adj[N];
vector<long long> power;
string S[1000000];
int L;
void add(char x){
    pref[len+1]=(x*power[len]+pref[len]);
    len++;
}
long long h(){
    int i=len-L;
    long long h=pref[i+L]-pref[i];
    h=h*power[N-i-L+1];
    return h;
}
void dfs(int v){
    for (auto x:S[v]){
        add(x);
        if(len>=L&& h()==need) ans++;
    }
    for(auto u:adj[v]) dfs(u);
    len-=S[v].size();
}

int main(){
    scanf("%d",&n);
    int cnt=n+1;
    for(int i=2;i<=n;i++){
        int pa;
        scanf("%d%s",&pa,&c);
        S[i]=c;
        adj[pa].push_back(i);
    }
    scanf("%s",&t);
    L=strlen(t);
    power.push_back(1);
    long long b[2]={1,1};
    for(int i=0;i<L;i++){
        need=t[i]*b[0]+need;
        b[0]=b[0]*base;
        power.push_back(b[0]);
    }
    for(int i=L;i<N;i++){
        b[0]=b[0]*base;
        power.push_back(b[0]);
    }
    need=need*power[N-L+1];
    dfs(1);
    printf("%lld\n",ans);
    return 0;
}