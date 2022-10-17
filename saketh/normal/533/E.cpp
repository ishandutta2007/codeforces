#include <iostream>
using namespace std;

int N;
string a, b;

bool check(string t, string u){
    int j = 0;
    int m = 0;

    for(int i=0; i<t.size(); i++)
        if(u[j] == t[i]) j++;
        else m++;
    return m==1;
}

int main(){
    cin >> N >> a >> b;

    int i=0;
    while(a[i] == b[i]) i++;

    int ans = 0;

    ans += check(a.substr(0, i) + b[i] + a.substr(i), b);
    ans += check(b.substr(0, i) + a[i] + b.substr(i), a);

    cout << ans << endl;
}