#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=998244353,MAX=1<<18,INF=1<<30;

int main(){
    
    //std::ifstream in("text.txt");
    //std::cin.rdbuf(in.rdbuf());
    
    int N;cin>>N;
    vector<int> A(N),rem(N);
    for(int i=0;i<N;i++){
        cin>>A[i];
        rem[i]=A[i]-2;
    }
    
    vector<pair<int,int>> B;
    int l=-1;
    for(int i=0;i<N;i++){
        if(A[i]>=2){
            if(l!=-1) B.push_back(make_pair(l,i));
            l=i;
        }
    }
    if(B.size()==0){
        rem[l]+=2;
    }else{
        for(int i=0;i<N;i++){
            if(A[i]>=2){
                rem[i]++;
                break;
            }
        }
        for(int i=N-1;i>=0;i--){
            if(A[i]>=2){
                rem[i]++;
                break;
            }
        }
    }
    
    bool check=true;
    int M;
    if(N-B.size()==1) M=B.size();
    else if(N-B.size()==2) M=B.size()+1;
    else M=B.size()+2;
    
    int ok=0;
    
    for(int i=0;i<N;i++){
        if(A[i]==1){
            if(ok==0){
                for(int j=0;j<N;j++){
                    if(rem[j]>=1){
                        B.push_back(make_pair(i,j));
                        rem[j]--;
                        ok++;
                        break;
                    }
                    if(j==N-1) check=false;
                }
            }else if(ok==1){
                for(int j=N-1;j>=0;j--){
                    if(rem[j]>=1){
                        B.push_back(make_pair(i,j));
                        rem[j]--;
                        ok++;
                        break;
                    }
                    if(j==0) check=false;
                }
            }else{
                for(int j=0;j<N;j++){
                    if(rem[j]>=1){
                        B.push_back(make_pair(i,j));
                        rem[j]--;
                        ok++;
                        break;
                    }
                    if(j==N-1) check=false;
                }
            }
        }
    }
    
    if(check){
        cout<<"YES "<<M<<endl;
        cout<<N-1<<endl;
        for(int i=0;i<N-1;i++){
            cout<<B[i].first+1<<" "<<B[i].second+1<<endl;
        }
    }else cout<<"NO"<<endl;
}