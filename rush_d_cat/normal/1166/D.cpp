#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;
int q; LL a,b,m,L[N],R[N];
void gensol(int pos,LL bb,vector<LL>&res){
    vector<LL> ans;
    ans.clear();
    ans.push_back(bb);
    //cout << "b=" << bb<<endl;
    while(pos>=2){
        pos--;
        LL rig=(bb-1)/2, lef=(bb-m+1)/2; 
        lef=max(lef,L[pos]);
        rig=min(rig,R[pos]);
        //printf("[%lld,%lld]\n", lef,rig);
        if(lef>rig){
            ans.clear(); return;
        }
        bb=lef; ans.push_back(bb); 
    }
    res.push_back(a);
    reverse(ans.begin(),ans.end());
    for(int i=1;i<ans.size();i++){
        res.push_back(ans[i]-ans[i-1]);
    }
    res.push_back(b);
}
int main() {
    scanf("%d",&q);
    while(q--) {
        scanf("%lld%lld%lld",&a,&b,&m);
        if(a==b) {
            printf("1 %lld\n", a); continue;
        }
        LL k=1,pos=2;
        // [k*(a+1), k*(a+m)]
        bool find=0;
        vector<LL> ans;
        L[1]=R[1]=a;
        for(k=1;;k<<=1,pos++){
            if(k*(a+1)>b) break;
            L[pos]=(k*2)*(a+1)-1, R[pos]=(k*2)*(a+m)-m;
            if(k*(a+m)>=b) {
                //printf("[%lld,%lld]\n",k*(a+1),k*(a+m));
                if(b<=k*a+(k-1)*m+1)
                    gensol(pos-1,b-1,ans);
                else
                    gensol(pos-1,k*a+(k-1)*m,ans);
                find=1; break;
            }
        }
        if(find==0 || ans.size()==0) {
            printf("-1\n"); continue;
        }
        printf("%d", ans.size());
        for(auto x:ans){
            printf(" %lld",x);
        }
        printf("\n");
    }   
}