#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    vector<string> strings;
    strings.resize(N);
    for(int j=0; j<N; j++){
        string yaystring;
        cin >> yaystring;
        strings[j] = yaystring;
    }
    for(int i=0; i<N; i++){
        string newstring = strings[i];
        int stringlen = newstring.length();
        string twoless = to_string(stringlen-2);
        string outputstring="";
        if(stringlen <= 10){
            outputstring = newstring;
        } else{
            outputstring=newstring[0]+twoless+newstring[stringlen-1];
        }
        cout << outputstring << endl;
    }
    return 0;
}