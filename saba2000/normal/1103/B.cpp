#include<bits/stdc++.h>
using namespace std;
bool ask(int x, int y){
    cout << "? "<<x <<" "<< y << endl;
    fflush(stdout);
    string a;
    cin >> a;
    if (a == "x") return 1;
    else return 0;
}
int game(){
    int i;
    if(ask(0, 1)) return 1;
    for( i = 1; i <= 30; i++){
        if(i == 30 || ask(1 << (i - 1), 1 << i)) break;
    }
    int s = 0;
    for(int j = i - 1; j >= 0; j--){
        if(ask(s, s + (1 << j))) continue;
        s += (1 << j);
    }
    return s + 1;

}
main(){
    string s;
    cin >> s;
    while(s == "start"){

        cout << "! " <<game() << endl;
        fflush(stdout);
        cin >> s;
    }
    return 0;
}