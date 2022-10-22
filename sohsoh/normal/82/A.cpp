#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    string persons[5] = {"Sheldon", "Leonard", "Penny", "Rajesh", "Howard"};

    int addingN = 1;
    int lastInd = -1;
    for (int i = 0; i < n; ) {
        lastInd += 1;
        if (lastInd > 4) {
            lastInd = 0;

            addingN *= 2;
        }

        i += addingN;
    }

    cout << persons[lastInd] << endl;

    return 0;
}