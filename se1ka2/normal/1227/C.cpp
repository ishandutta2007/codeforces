#include <iostream>
#include <string>
using namespace std;

int main()
{
    int t;
    cin >> t;
    for(int c = 0; c < t; c++){
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        cout << n << endl;
        for(int i = 0; i < k * 2 - 2; i++){
            if(i % 2 == 0){
                int j = i;
                for(; j < n; j++) if(s[j] == '(') break;
                cout << i + 1 << " " << j + 1 << endl;
                swap(s[i], s[j]);
            }
            else{
                int j = i;
                for(; j < n; j++) if(s[j] == ')') break;
                cout << i + 1 << " " << j + 1 << endl;
                swap(s[i], s[j]);
            }
        }
        for(int i = k * 2 - 2; i < (n + (k * 2 - 2)) / 2; i++){
            int j = i;
            for(; j < n; j++) if(s[j] == '(') break;
            cout << i + 1 << " " << j + 1 << endl;
            swap(s[i], s[j]);
        }
        for(int i = (n + (k * 2 - 2)) / 2; i < n; i++){
            int j = i;
            for(; j < n; j++) if(s[j] == ')') break;
            cout << i + 1 << " " << j + 1 << endl;
            swap(s[i], s[j]);
        }
    }
}