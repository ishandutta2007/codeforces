#include <bits/stdc++.h>
using namespace std;

int main(void){

    long long int n;
    cin>>n;
    long long int res=0;
    long long int cont=0;
    priority_queue<long long int> a, b, c;
    string S;
    long long int A;
    for(long long int i=0;i<n;i++){
        cin>>S>>A;
        if(S=="11"){
            res+=A;
            cont++;
        }
        else if(S=="00") c.push(A);
        else if(S=="10") a.push(A);
        else if(S=="01") b.push(A);
    }
    //long long int aux=0;
    //long long int k=cont;
    //cout<<cont<<endl;

    long long int conta=cont;
    long long int contb=cont;
    long long int B = b.size();
    long long int C = a.size();
    for(long long int i=0;i<min(B, C);i++){
        res+=b.top();
        res+=a.top();
        b.pop();
        a.pop();
        cont+=2;
        conta++;
        contb++;
    }

    //priority_queue<long long int> pq;
    while(!a.empty()){
        c.push(a.top());
        a.pop();
    }
    while(!b.empty()){
        c.push(b.top());
        b.pop();
    }

    //cout<<conta<<" "<<contb<<" "<<cont<<endl;

    while(conta> cont/2 && contb > cont/2 && !c.empty()){
        res+=c.top();
        c.pop();
        cont++;
    }

    cout<<res<<endl;

    return 0;
}