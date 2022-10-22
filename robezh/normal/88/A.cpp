#include<cstdio>
#include<iostream>
#include<map>
#include<string>
using namespace std;

map<string, int> M;

int dis(string a, string b) {
    return (M[b] + 12 - M[a]) % 12;
}

int check(string a, string b, string c) {
    if(dis(a, b) == 4 && dis(b, c) == 3) return 1;
    else if(dis(a, b) == 3 && dis(b, c) == 4) return -1;
    return 0;
}

string solve(string a, string b, string c) {
    for(int i = -1; i <= 1; i+=2)
        if(check(a,b,c) == i || check(a,c,b) == i || 
		check(b,a,c) == i || check(b,c,a) == i || check(c,a,b) == i || check(c,b,a) == i) return i == -1 ? "minor" : "major";
    return "strange";
}

int main() {
    string str[12] = {"C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "B", "H"};
    for(int i = 0; i < 12; i++) M[str[i]] = i;
    string a,b,c;
    cin>>a>>b>>c;
    cout<<solve(a,b,c);
}