#include <iostream>
#include <string>
using namespace std;
int values[26];
int main(){
    string a;
    int k;
    cin >> a >> k;
    int max = 0;
    for(int i = 0; i < 26;i++){
        cin >> values[i];
        if(values[i] > max){
            max = values[i];
        }
    }
    long long counter = 0;
    for(int i = 1; i <= a.length(); i++){
        counter += values[int(a[i-1])-'a']*i;
    }
    for(int i = a.length()+1; i <= k+a.length();i++){
        counter += max*i;
    }
    cout << counter << endl;
    return 0;
}