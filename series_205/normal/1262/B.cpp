#include <iostream>
using namespace std;
int t,n[100000];
int main(){
    cin>>t;
    for(int j=0;j<t;j++){
        int q[100001]={},p[100001]={};
        cin>>n[j];
        bool ok=1;
        bool used[100001]={};
        for(int i=1;i<=n[j];i++){
            cin>>q[i];
            if(q[i]<i){
                ok=0;
            }
            if(q[i-1]<q[i]){
                p[i]=q[i];
                used[p[i]]=1;
            }
        }
        int x=1;
        if(ok==0){
            cout<<-1;
        }else{
            for(int i=1;i<=n[j];i++){
                if(i!=1)cout<<" ";
                if(p[i])cout<<p[i];
                else{
                    while(used[x])x++;
                    cout<<x;
                    x++;
                }
            }
        }
        cout<<endl;
    }
}