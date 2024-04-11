#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n;
    cin >> n;

    string s;
    cin >> s;
    
    if(n == 1){
       cout << "Yes";
        return 0; 
    }

    vector<int> a(256, 0);
    for(int i = 0; i < n; i++){
        a[s[i]]++;
    }

    for(int i = 0; i < a.size(); i++)
        if(a[i] >= 2){
            cout << "Yes";
            return 0;
        }

    cout << "No";
}