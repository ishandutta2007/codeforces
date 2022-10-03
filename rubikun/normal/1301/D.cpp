#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=200005,INF=1<<30;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int H,W,K;cin>>H>>W>>K;
    if(H==1){
        if(K<=W-1){
            cout<<"YES"<<endl;
            cout<<1<<endl;
            cout<<K<<" "<<"R"<<endl;
        }else if(K<=2*(W-1)){
            cout<<"YES"<<endl;
            cout<<2<<endl;
            cout<<W-1<<" "<<"R"<<endl;
            cout<<K-(W-1)<<" "<<"L"<<endl;
        }else cout<<"NO"<<endl;
    }else if(W==1){
        if(K<=H-1){
            cout<<"YES"<<endl;
            cout<<1<<endl;
            cout<<K<<" "<<"D"<<endl;
        }else if(K<=2*(H-1)){
            cout<<"YES"<<endl;
            cout<<2<<endl;
            cout<<H-1<<" "<<"D"<<endl;
            cout<<K-(H-1)<<" "<<"U"<<endl;
        }else cout<<"NO"<<endl;
    }else{
        if(K>4*H*W-2*H-2*W){
            cout<<"NO"<<endl;
            return 0;
        }
        H--;W--;
        
        cout<<"YES"<<endl;
        
        vector<int> a;
        vector<string> b;
        
        if(H>=K){
            a.push_back(K);
            b.push_back("D");
        }else if(2*H>=K){
            a.push_back(H);
            b.push_back("D");
            
            a.push_back(K-H);
            b.push_back("U");
        }else{
            K-=2*H;
            a.push_back(H);
            b.push_back("D");
            
            a.push_back(H);
            b.push_back("U");
            
            int cnt=0;
            while(cnt<W&&K){
                if(3*H>=K){
                    if(K>=3){
                        a.push_back(K/3);
                        b.push_back("RDL");
                        K%=3;
                    }
                    if(K==1){
                        a.push_back(1);
                        b.push_back("R");
                    }else if(K==2){
                        a.push_back(1);
                        b.push_back("RD");
                    }
                    K=0;
                    break;
                }else if(K==3*H+1){
                    a.push_back(K/3);
                    b.push_back("RDL");
                    
                    a.push_back(1);
                    b.push_back("R");
                    K=0;
                    break;
                }else if(K<=4*H+1){
                    a.push_back(H);
                    b.push_back("RDL");
                    
                    a.push_back(1);
                    b.push_back("R");
                    
                    K-=3*H+1;
                    
                    a.push_back(K);
                    b.push_back("U");
                    K=0;
                    break;
                }else{
                    a.push_back(H);
                    b.push_back("RDL");
                    
                    a.push_back(1);
                    b.push_back("R");
                    
                    a.push_back(H);
                    b.push_back("U");
                    
                    K-=4*H+1;
                }
                
                cnt++;
            }
            
            if(K){
                a.push_back(K);
                b.push_back("L");
            }
        }
        
        cout<<a.size()<<endl;
        
        for(int i=0;i<a.size();i++){
            cout<<a[i]<<" "<<b[i]<<endl;
        }
    }
    
}