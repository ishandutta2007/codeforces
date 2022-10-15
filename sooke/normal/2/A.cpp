#include <iostream>
#include <map>

using namespace std;

map < string , int > M , P;

string s[1001];
int n , m , x = -210000000 , a[1001];

int main(){
    cin >> n;
    for(int i = 1 ; i <= n ; i++)
        cin >> s[i] >> a[i] , M[s[i]] += a[i];
    for(int i = 1 ; i <= n ; i++)
        if(x < M[s[i]])
            x = M[s[i]];
    for(int i = 1 ; i <= n ; i++){
        P[s[i]] += a[i];
        if(x <= P[s[i]] && M[s[i]] == x){
            cout << s[i];
            break;
        }
    }
    return 0;
}