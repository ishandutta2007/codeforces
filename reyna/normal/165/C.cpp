#include <iostream>
#include <string>
#include <vector>
using namespace std;
vector<int> O;
int main(){
    int k;
    cin >> k;
    string a;
    cin >> a;
    long long counter = 1;
    for(int i = 0; i < a.length();i++){
        if(a[i] == '1'){
            O.push_back(counter);
            counter = 1;
        }else{
            counter++;
        }
    }
    O.push_back(counter);
    counter = 0;
    for(int i = k ; i < O.size();i++){
        if(k == 0)
            counter+= (long long)O[i]*(O[i]-1)/2;
        else
            counter+=(long long)O[i]*O[i-k];
    }
    cout << counter << endl;
    return 0;
}