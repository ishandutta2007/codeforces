#include<bits/stdc++.h>
using namespace std;
int maxf(int a,int b,int c,int d,int e){
    int t1,t2;
    if(a>b){
        if(a>c){
            t1=a;
        }
        else{
            t1=c;
        }
    }
    else{
        if(b>c){
            t1=b;
        }
        else{
            t1=c;
        }
    }

    if(d>e){
        t2=d;

    }
    else{
        t2=e;
    }
    if(t1>t2){
        return t1;
    }
    else
    {
        return t2;
    }
    
}
int main(){

    int n,m;
    cin >> n >> m;
    string answers[n];
    int marks[m];
    int r=0;
    for(int i =0 ; i<n;i++){
        cin >> answers[i];
    }
    for(int h =0 ; h<m;h++){
        cin >> marks[h];
    }
    for(int k =0; k<m ; k++){
        int a,b,c,d,e;
        a=b=c=d=e=0;
       for(int j=0;j<n;j++){
        if(answers[j][k]=='A')
         a++;
        if(answers[j][k]=='B')
         b++; 
        if(answers[j][k]=='C')
         c++; 
        if(answers[j][k]=='D')
         d++;
        if(answers[j][k]=='E')
         e++;
     
       }
       r = r + marks[k]*maxf(a,b,c,d,e);
         

    }
   

    cout<<r;

}