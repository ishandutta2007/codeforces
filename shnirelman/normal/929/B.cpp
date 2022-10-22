#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n, k;
    cin >> n >> k;

    vector<string> s(n);
    for(int i = 0; i < n; i++)cin >> s[i];

    for(int i = 0; i < n; i++){
        for(int j = 0; j < 12; j++){
            if(s[i][j] == '.'){
                int cnt = 0;
                if(j == 0){
                    if(s[i][1] == 'S')cnt++;
                }
                else if(j == 11){
                    if(s[i][10] == 'S')cnt++;
                }
                else{
                    if(s[i][j+1] == 'S')cnt++;
                    if(s[i][j-1] == 'S')cnt++;
                }
                if(k > 0 && cnt == 0){
                    k--;
                    s[i][j] = 'x';
                }

            }
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < 12; j++){
            if(s[i][j] == '.'){
                int cnt = 0;
                if(j == 0){
                    if(s[i][1] == 'S')cnt++;
                }
                else if(j == 11){
                    if(s[i][10] == 'S')cnt++;
                }
                else{
                    if(s[i][j+1] == 'S')cnt++;
                    if(s[i][j-1] == 'S')cnt++;
                }
                if(k > 0 && cnt == 1){
                    k--;
                    s[i][j] = 'x';
                }

            }
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < 12; j++){
            if(s[i][j] == '.'){
                int cnt = 0;
                if(j == 0){
                    if(s[i][1] == 'S')cnt++;
                }
                else if(j == 11){
                    if(s[i][10] == 'S')cnt++;
                }
                else{
                    if(s[i][j+1] == 'S')cnt++;
                    if(s[i][j-1] == 'S')cnt++;
                }
                if(k > 0){
                    k--;
                    s[i][j] = 'x';
                }

            }
        }
    }

    int ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 12; j++){
            if(s[i][j] == 'S'){
                int cnt = 0;
                if(j == 0){
                    if(s[i][1] != '.' && s[i][1] != '-')cnt++;
                }
                else if(j == 11){
                    if(s[i][10] != '.' && s[i][10] != '-')cnt++;
                }
                else{
                    if(s[i][j + 1] != '.' && s[i][j + 1] != '-')cnt++;
                    if(s[i][j - 1] != '.' && s[i][j - 1] != '-')cnt++;
                }

                ans += cnt;
            }
        }
    }

    cout << ans << endl;
    for(int i = 0; i < n; i++)cout << s[i] << endl;
}