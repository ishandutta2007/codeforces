#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    char mas[300];
    int non[300];


    cin>>mas;
    int l = strlen(mas);

    int g = l-1;
    for(int i=l-1;i>0;i--){
        if(mas[i]=='/' && mas[i-1]=='/'){
            non[g]=i;
            g--;
        }
    }
    int d=l;
    char tut;
    int k=l-1;
    tut=mas[k];
    while(tut=='/'){
        tut=mas[k];
        if(tut=='/'){
            d--;
        }
        k--;
    }
    for(int i=0;i<d;i++){
        if(g+1 <= l-1 && non[g+1]==i){
            g++;
        }else{
        cout<<mas[i];
        }
    }
    if(d==0){
        cout<<'/';
    }
}