#include <iostream>

using namespace std;
int cafes[200001];
bool visited[200001];
int main() {
    int n;
    cin >> n;
    int ans = 0;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        cafes[i] = x;
    }
    for(int i = n-1; i > -1; i--){
        if(visited[cafes[i]] == 0){
            visited[cafes[i]] = 1;
            ans = i;
        }
    }
    cout << cafes[ans];
}