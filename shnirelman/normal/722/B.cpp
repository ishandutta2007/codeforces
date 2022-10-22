#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++)cin >> a[i];

    string vowels = "aeiouy";

    string s1;
    getline(cin, s1);
    for(int i = 0; i < n; i++){
        string s;
        getline(cin, s);

        int cnt = 0;
        for(int j = 0; j < s.length(); j++)
            if(vowels.find(s[j]) != size_t(-1))cnt++;

        if(cnt != a[i]){
            cout << "NO";
            return 0;
        }
    }

    cout << "YES";
}