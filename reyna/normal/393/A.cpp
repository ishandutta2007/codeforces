#include<iostream>
#include<string>
using namespace std;
int main(){
    string a;
    int e=0,i=0,n=0,t=0;
    cin >> a;
    for(int k = 0; k < a.length(); k++){
        if(a[k] == 'e'){
            e++;
        }else if(a[k] == 'i'){
            i++;
        }else if(a[k] == 'n'){
            n++;
        }else if(a[k] == 't'){
            t++;
        }
    }
    int min = 101;
    if((n-1)/2 < min){
        min = (n-1)/2;
    }
    if(e/3 < min){
        min = e/3;
    }
    if(t < min){
        min = t;
    }
    if(i < min){
        min = i;
    }
    cout << min;
}