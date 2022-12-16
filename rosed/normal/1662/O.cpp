#include <bits/stdc++.h>

#ifndef LOCAL_DEBUG
__attribute((constructor)) void before_main() { std::ios_base::sync_with_stdio(false);std::cin.tie(0);std::cout.tie(0); }
#endif
void fk(){ std::cerr<<'\n'; } template<class fst,class...lst>
void fk(fst F, lst... L) { std::cerr<<F<<' '; fk(L...); }
#define all(x) x.begin(),x.end()
#define pb emplace_back
using ll=long long;

std::pair<int,int> mv[4]={{0,1},{0,-1},{1,0},{-1,0}};

int main(){
    int T; std::cin>>T;
    while(T--){
        int n; std::cin>>n;
        std::vector<std::vector<int>>mp(45,std::vector<int>(720,true));
        while(n--){
            char op; std::cin>>op;
            if(op=='C'){
                int r,a1,a2; std::cin>>r>>a1>>a2;
                r<<=1; a1<<=1; a2<<=1;
                int i=a1;
                do{ mp[r][i]=false; i=(i+1)%720; }while(i!=a2);
            }else{
                int a,r1,r2; std::cin>>r1>>r2>>a;
                r1=(r1<<1); r2=(r2<<1); a<<=1;
                for(int i=r1;i<=r2;++i) mp[i][a]=false;
            }
        }
        std::queue<std::pair<int,int>>q;
        std::vector<std::vector<char>>vis(45,std::vector<char>(720,false));
        bool fail=true;
        for(int i=0;i<720;++i) q.push({0,i});
        while(!q.empty()){
            auto [r,a]=q.front(); q.pop();
            if(r==42){
                fail=false;
                break;
            }
            for(auto &[dx,dy]: mv){
                int nr=r+dx,na=(a+dy+720)%720;
                if(nr<0||vis[nr][na]||!mp[nr][na]) continue;
                q.push({nr,na});
                vis[nr][na]=true;
            }
        }
        std::cout<<(fail?"NO":"YES")<<'\n';
    }
    return 0;
}