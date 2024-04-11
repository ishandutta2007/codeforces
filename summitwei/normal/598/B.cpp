#include <bits/stdc++.h>
using namespace std;

vector<int> rotatePlaces(vector<int> placements, int a, int b, int rotAmount){
    int k;
    if(b != a){
        k = rotAmount % (b-a+1);
    } else{
        k = 1;
    }

    vector<int> copiedPlaces = placements;
    for(int i=a; i<b+1; i++){
        int newLoc = i+k;
        if(newLoc > b){
            newLoc = newLoc - (b-a+1);
        }
        copiedPlaces[newLoc] = placements[i];
    }

    return copiedPlaces;
}

int main(){
    string a;
    cin >> a;
    int N;
    cin >> N;

    vector <int> answers;
    answers.resize(a.length());
    for(int blah = 0; blah < a.length(); blah++){
        answers[blah] = blah;
    }

    for(int i=0; i<N; i++){
        int dab, onem, haters;
        cin >> dab >> onem >> haters;
        dab -= 1;
        onem -= 1;
        answers = rotatePlaces(answers, dab, onem, haters);
    }

    /*vector <int> newVec = rotatePlaces(answers, 0, 5, 3);

    for(int j=0; j<a.length(); j++){
        cout << newVec[j] << endl;
    }*/

    string outputString = "";
    for(int j=0; j<a.length(); j++){
        outputString += a[answers[j]];
    }

    //reverse(outputString.begin(), outputString.end());
    cout << outputString;
    return 0;
}