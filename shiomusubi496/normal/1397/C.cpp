#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
    int N;
    cin>>N;
    vector<int> A(N);
    for(int &i:A)cin>>i;
    if(N==1){
        cout<<"1 1\n"<<-A[0]<<"\n1 1\n0\n1 1\n0\n";
        return 0;
    }
    puts("1 1");
    cout<<-A[0]<<endl;
    cout<<"2 "<<N<<endl;
    for(int i=1;i<N;i++)cout<<A[i]*(N-1)<<(i==N-1?'\n':' ');
    cout<<"1 "<<N<<endl<<"0 ";
    for(int i=1;i<N;i++)cout<<-A[i]*N<<(i==N-1?'\n':' ');
}