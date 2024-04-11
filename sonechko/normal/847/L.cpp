#include <bits/stdc++.h>
using namespace std;



int n;
vector<pair<int,int> > ans;
bool used[100005];
vector<int> v[100005],vv[100005];
int kol[100005];
int all;
int to[100005];
bool used2[100005];
vector<int> v2[100005];
int cl[100005];
set<int> ss;
inline void solve(int x){
    ss.erase(x);
    --kol[x];
    int yy=0;
    for (int i=0;i<v[x].size();++i) {
        int y=v[x][i];
        if (used[y]==false) {
            used[y]=true;
            yy=y;
            break;
        }
    }
    ans.push_back(make_pair(to[x],yy));
    for (int i=0;i<vv[yy].size();++i) {
        int to=vv[yy][i];
        --kol[to];
        if (kol[to]==1) {
            ss.insert(to);
        }
    }
}
void dfs(int x,int y,int z){
    used2[x]=true;
    cl[x]=z;
    for (int i=0;i<v2[x].size();++i) {
        int too=v2[x][i];
        if (too==y) continue;
        if (used2[too]==false) dfs(too,x,z);
    }
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;++i) {
        /*
        int m;
        cin>>m;
        char c;
        for (int j=1;j<=m;++j) {
            cin>>c;
            int mm;
            cin>>mm;
            ++all;
            kol[all]=m;
            to[all]=i;
            for (int k=1;k<=mm;++k) {
                if (k>1) cin>>c;
                int x;
                cin>>x;
                v[all].push_back(x);
                vv[x].push_back(all);
                if (mm==1) {
                    ss.insert(all);
                }
            }
        }
        */
        string s;
        cin>>s;
        for (int j=0;j<s.size();) {
            int mm=0;
            int pos=j;
            while (s[pos]>='0' && s[pos]<='9') {
                mm=(mm*10+s[pos]-'0');
                ++pos;
            }
            ++pos;
            ++all;
            kol[all]=mm;
            to[all]=i;
            if (mm==1) {
                ss.insert(all);
            }
            while (mm) {
                int nw=0;
                while (pos<s.size() && s[pos]>='0' && s[pos]<='9') {
                    nw=nw*10+s[pos]-'0';
                    ++pos;
                }
                --mm;
                v[all].push_back(nw);
                vv[nw].push_back(all);
                ++pos;
            }
            j=pos;
        }
    }

    while (!ss.empty()) {
        int x=*ss.begin();
        if (kol[x]!=1) {
            ss.erase(x);
            continue;
        }
        solve(x);
    }
    if (ans.size()!=n) {
        cout<<"-1";
        return 0;
    }
    for (int i=0;i<ans.size()-1;++i) {
        int x=ans[i].first;
        int y=ans[i].second;
        v2[x].push_back(y);
        v2[y].push_back(x);
    }
    for (int i=1;i<=all;++i) {
        for (int j=1;j<=n;++j)
            used2[j]=false;
        cl[to[i]]=0;
            int nw=0;
            int zz=to[i];
        for (int j=0;j<v2[zz].size();++j) {
            int too=v2[zz][j];
            dfs(too,to[i],++nw);
        }
        int cl2=0;
        for (int j=1;j<v[i].size();++j) {
            int x=v[i][j-1];
            int y=v[i][j];
            if (cl[x]!=cl[y]) {
                cout<<"-1";
                return 0;
            }
        }
        int zz2=v[i][0];
        for (int j=1;j<=n;++j)
            if (cl[j]==cl[zz2]) ++cl2;
        if (cl2!=v[i].size()) {
            cout<<"-1";
            return 0;
        }
    }
    cout<<n-1<<'\n';
    for (int i=0;i<ans.size()-1;++i)
        cout<<ans[i].first<<" "<<ans[i].second<<'\n';
}