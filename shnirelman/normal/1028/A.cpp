#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n, m;
    cin >> n >> m;

    vector<string> s(n);
    for(int i = 0; i < n; i++)cin >> s[i];


    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++){
            if(s[i][j] == 'B'){
                int a = 0;
                while(j < m && s[i][j] == 'B'){
                    j++;
                    a++;
                }
                cout << i + a / 2 + 1 << ' ' << j - a / 2;
                return 0;
            }
        }
}