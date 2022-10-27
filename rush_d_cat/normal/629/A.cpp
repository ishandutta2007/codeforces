#include<iostream>
using namespace std;
int main(){
    char map[100+2][100+2];
    int n;cin>>n;
    for(int i=0;i<n;i++){
        scanf("%s",map[i]);
    }
    __int64 res=0;
    int cnt;
    for(int i=0;i<n;i++){
        cnt=0;
        for(int j=0;j<n;j++){
            if(map[i][j]=='C') cnt++;
        }
        res+=cnt*(cnt-1)/2;
    }
    for(int i=0;i<n;i++){
        cnt=0;
        for(int j=0;j<n;j++){
            if(map[j][i]=='C') cnt++;
        }
        res+=cnt*(cnt-1)/2;
    }
    cout<<res<<endl;
    return 0;
}