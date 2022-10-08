#include<bits/stdc++.h>
using namespace std;
int f[1009];
vector<int> v;
main(){
    int n;
    cin >> n;
    int A,B;
    cin>>A>>B;
    vector<int> v;
    for(int i = 2; i*i <= A; i++){
        if(A % i == 0){
            v.push_back(i);
            while(A%i==0)
                A/=i;
        }
    }
    if(A > 1) v.push_back(A);
    A=B;
    for(int i = 2; i*i <= A; i++){
        if(A % i == 0){
            v.push_back(i);
            while(A%i==0)
                A/=i;
        }
    }
    if(A > 1) v.push_back(A);
    for(int i = 1; i < n; i++){
        int a,b;
        cin>>a>>b;
        for(int i = 0; i < v.size(); i++){
            if(a % v[i] == 0 || b % v[i] == 0) f[i]++;
        }
    }
   for(int i = 0; i < v.size(); i++){
        if(f[i] == n - 1){
            cout<<v[i]<<endl;
            return 0;
        }
   }
cout<<-1<<endl;
}