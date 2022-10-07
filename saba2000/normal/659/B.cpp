#include<iostream>
#include<algorithm>
using namespace std;

struct participant {
    char nume[12];
    int regiune;
    int punctaj;
};

participant x[100100];

int comp(participant A, participant B) {
    if (A.regiune == B.regiune)
        return A.punctaj > B.punctaj;
    return A.regiune < B.regiune;
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        cin >> x[i].nume >> x[i].regiune >> x[i].punctaj;
    sort(x + 1, x + n + 1, comp);
    int inceput = 1;
    for (int i = 1; i <= n; ++i)
        if (x[i].regiune != x[i + 1].regiune) {
            if (inceput + 2 <= i && x[inceput + 1].punctaj == x[inceput + 2].punctaj)
                cout << "?";
            else
                cout << x[inceput].nume << " " << x[inceput + 1].nume;
            cout << "\n";
            inceput = i + 1;
        }
    return 0;
}