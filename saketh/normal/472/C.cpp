#include <iostream>
using namespace std;

int N;
string name[100005][2];
int order[100005];

int main(){
    ios_base::sync_with_stdio(false);

    cin >> N;
    for(int i=0; i<N; i++)
        cin >> name[i][0] >> name[i][1];

    for(int i=0; i<N; i++)
        cin >> order[i];

    string prev = "";
    bool good = true;

    for(int j=0; j<N; j++){
        int i = order[j] - 1;

        string f = min(name[i][0], name[i][1]);
        string s = max(name[i][0], name[i][1]);

        if(f > prev) prev = f;
        else if(s > prev) prev = s;
        else{
            good = false;
            break;
        }
    }

    if(good) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}