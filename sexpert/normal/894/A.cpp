#include <iostream>
#include <string>

using namespace std;

int main()
{
    int totalQ = 0, countQAQ = 0, countQ = 0;
    string s;
    string filteredWord;
    cin >> s;
    for(int i = 0; i <= s.length(); i++)
    {
        switch(s[i])
        {
            case 'Q':
                totalQ++;
                filteredWord += s[i];
                break;
            case 'A':
                filteredWord += s[i];
                break;
            default:
                break;
        }
    }
    for(int i = 0; i <= filteredWord.length(); i++)
    {
        switch(filteredWord[i])
        {
            case 'Q':
                countQ++;
                break;
            case 'A':
                countQAQ += (countQ)*(totalQ - countQ);
                break;
        }
    }
    cout << countQAQ;
    return 0;
}