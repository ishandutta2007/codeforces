#include <iostream>
#include <cstring>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;
const int N=1000000+10;
int n; string s[N];
vector< pair<int,string> > v[200];
bool vo[1000];
bool cmp(string s1,string s2){
    int c1=0; char ch1;
    int c2=0; char ch2;
    for(int i=0;s1[i];i++) if(vo[s1[i]]) c1++, ch1=s1[i];
    for(int i=0;s2[i];i++) if(vo[s2[i]]) c2++, ch2=s2[i];
    return make_pair(ch1,c1)<make_pair(ch2,c2);
}
bool eq(string s1,string s2){
    int c1=0; char ch1;
    int c2=0; char ch2;
    for(int i=0;s1[i];i++) if(vo[s1[i]]) c1++, ch1=s1[i];
    for(int i=0;s2[i];i++) if(vo[s2[i]]) c2++, ch2=s2[i];
    return make_pair(ch1,c1)==make_pair(ch2,c2);
}
bool cmp2(string s1,string s2) {
    int c1=0; char ch1;
    int c2=0; char ch2;
    for(int i=0;s1[i];i++) if(vo[s1[i]]) c1++, ch1=s1[i];
    for(int i=0;s2[i];i++) if(vo[s2[i]]) c2++, ch2=s2[i];
    return c1<c2;    
}
bool eq2(string s1,string s2){
    int c1=0; char ch1;
    int c2=0; char ch2;
    for(int i=0;s1[i];i++) if(vo[s1[i]]) c1++, ch1=s1[i];
    for(int i=0;s2[i];i++) if(vo[s2[i]]) c2++, ch2=s2[i];
    return c1==c2;
}
vector< pair<string,string> > v1,v2;
int vis[N]; bool fg[N];
int main() {
    //cout<<(int)'a'<<endl;
    ios::sync_with_stdio(false);
    cin>>n; vo['a']=vo['e']=vo['i']=vo['o']=vo['u']=1;
    for(int i=1;i<=n;i++) cin>>s[i];
    sort(s+1,s+1+n,cmp);
    for(int i=1;i<=n;i++){
        if(vis[i]==0) {
            if(eq(s[i],s[i+1])) {
                //cout<<"#"<<s[i]<<" "<<s[i+1]<<endl;
                v1.push_back(make_pair(s[i],s[i+1])); vis[i]=vis[i+1]=1;
            }
        }
    }
    vector<string> v;
    for(int i=1;i<=n;i++){
        if(vis[i]==0) {
            v.push_back(s[i]);
        }
    }
    sort(v.begin(),v.end(),cmp2);


    for(int i=0;i<(int)v.size()-1;i++){
        if(fg[i]) continue;
        if(eq2(v[i],v[i+1])) {
            fg[i]=fg[i+1]=1; v2.push_back(make_pair(v[i],v[i+1]));
        }
    }

    int m=min(v1.size(), v2.size()+(v1.size()-v2.size())/2);
    cout<<m<<endl;
    int x=0,y=0;
    for(int i=1;i<=m;i++) {
        if(x<v2.size() && y<v1.size()){
            cout<<v2[x].first<<" "<<v1[y].first<<endl;
            cout<<v2[x].second<<" "<<v1[y].second<<endl; x++, y++;
        } else {
            cout<<v1[y].first<<" "<<v1[y+1].first<<endl;
            cout<<v1[y].second<<" "<<v1[y+1].second<<endl; y+=2;
        }
    }
}