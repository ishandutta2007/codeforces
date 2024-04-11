#include <bits/stdc++.h>
using namespace std;

string str;

int main(){
    getline(cin, str);
    for(int i = 1; i < str.length(); i++){
        if(str[i-1] > str[i]) return !printf("NO");
    }
    int a,b,c;
    a = b = c = 0;
    for(char ch : str){
        if(ch == 'a') a++;
        else if(ch == 'b') b++;
        else c++;
    }
    //cout << a << b << c;
    if(a == 0 || b == 0) return !printf("NO");
    if(a == c || b == c) return !printf("YES");
    else return !printf("NO");
}