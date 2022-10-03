#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=100005,INF=1<<30;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int H,W;cin>>H>>W;
    vector<vector<char>> S(H,vector<char>(W)),ans(H,vector<char>(W));
    int mini=H*W;
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            cin>>S[i][j];
        }
    }
    string AGCT="AGCT";
    vector<int> id={0,0,1,1};
    
    do{
        int a=-1,b=-1,c=-1,d=-1;
        for(int i=0;i<4;i++){
            if(id[i]==0){
                if(a==-1) a=i;
                else b=i;
            }else{
                if(c==-1) c=i;
                else d=i;
            }
        }
        vector<vector<char>> T(H,vector<char>(W));
        vector<char> L(H),R(H);
        for(int i=0;i<H;i++){
            if(i%2==0){
                L[i]=AGCT[a];
                R[i]=AGCT[b];
            }else{
                L[i]=AGCT[b];
                R[i]=AGCT[a];
            }
        }
        for(int j=0;j<W;j+=2){
            int cnt1=0,cnt2=0;
            for(int i=0;i<H;i++){
                if(L[i]!=S[i][j]) cnt1++;
            }
            for(int i=0;i<H;i++){
                if(R[i]!=S[i][j]) cnt2++;
            }
            if(cnt1<cnt2){
                for(int i=0;i<H;i++) T[i][j]=L[i];
            }else{
                for(int i=0;i<H;i++) T[i][j]=R[i];
            }
        }
        
        for(int i=0;i<H;i++){
            if(i%2==0){
                L[i]=AGCT[c];
                R[i]=AGCT[d];
            }else{
                L[i]=AGCT[d];
                R[i]=AGCT[c];
            }
        }
        
        for(int j=1;j<W;j+=2){
            int cnt1=0,cnt2=0;
            for(int i=0;i<H;i++){
                if(L[i]!=S[i][j]) cnt1++;
            }
            for(int i=0;i<H;i++){
                if(R[i]!=S[i][j]) cnt2++;
            }
            if(cnt1<cnt2){
                for(int i=0;i<H;i++) T[i][j]=L[i];
            }else{
                for(int i=0;i<H;i++) T[i][j]=R[i];
            }
        }
        
        int sum=0;
        
        for(int i=0;i<H;i++){
            for(int j=0;j<W;j++){
                if(S[i][j]!=T[i][j]) sum++;
            }
        }
        
        if(sum<mini){
            mini=sum;
            ans=T;
        }
        
    }while(next_permutation(all(id)));
    
    id[0]=0;
    id[1]=0;
    id[2]=1;
    id[3]=1;
    
    do{
        int a=-1,b=-1,c=-1,d=-1;
        for(int i=0;i<4;i++){
            if(id[i]==0){
                if(a==-1) a=i;
                else b=i;
            }else{
                if(c==-1) c=i;
                else d=i;
            }
        }
        vector<vector<char>> T(H,vector<char>(W));
        vector<char> L(W),R(W);
        for(int i=0;i<W;i++){
            if(i%2==0){
                L[i]=AGCT[a];
                R[i]=AGCT[b];
            }else{
                L[i]=AGCT[b];
                R[i]=AGCT[a];
            }
        }
        for(int j=0;j<H;j+=2){
            int cnt1=0,cnt2=0;
            for(int i=0;i<W;i++){
                if(L[i]!=S[j][i]) cnt1++;
            }
            for(int i=0;i<W;i++){
                if(R[i]!=S[j][i]) cnt2++;
            }
            if(cnt1<cnt2){
                for(int i=0;i<W;i++) T[j][i]=L[i];
            }else{
                for(int i=0;i<W;i++) T[j][i]=R[i];
            }
        }
        
        for(int i=0;i<W;i++){
            if(i%2==0){
                L[i]=AGCT[c];
                R[i]=AGCT[d];
            }else{
                L[i]=AGCT[d];
                R[i]=AGCT[c];
            }
        }
        
        for(int j=1;j<H;j+=2){
            int cnt1=0,cnt2=0;
            for(int i=0;i<W;i++){
                if(L[i]!=S[j][i]) cnt1++;
            }
            for(int i=0;i<W;i++){
                if(R[i]!=S[j][i]) cnt2++;
            }
            if(cnt1<cnt2){
                for(int i=0;i<W;i++) T[j][i]=L[i];
            }else{
                for(int i=0;i<W;i++) T[j][i]=R[i];
            }
        }
        
        int sum=0;
        
        for(int i=0;i<H;i++){
            for(int j=0;j<W;j++){
                if(S[i][j]!=T[i][j]) sum++;
            }
        }
        
        if(sum<mini){
            mini=sum;
            ans=T;
        }
        
    }while(next_permutation(all(id)));
    
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            cout<<ans[i][j];
        }
        cout<<endl;
    }
}