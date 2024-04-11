#include <iostream>
#include <string>
#include <string.h>
#include <cstring>

using namespace std;

class string_set
{
private:
    //struct tree {int words; tree * next[26];};
    struct tree {int words; char letter; tree * next, * left;};
    tree * T;
public:
    //string_set() {T = new tree; T->words = 0; for (int i = 0; i < 26; i ++) T->next[i] = NULL;};
    string_set() {T = new tree; T->words = T->letter = 0; T->next = T->left = NULL;};
    void insert(char word[])
    {
        int n = strlen(word);
        tree * cur = T;
        for (int i = 0; i < n; i ++)
        {
            if (cur->next == NULL)
            {
                cur->next = new tree;
                cur->next->letter = word[i];
                cur->next->next = cur->next->left = NULL;
                cur->next->words = 0;
                cur = cur->next;
                continue;
            }
            cur = cur->next;

            bool have = false;
            while (cur->left != NULL)
            {
                if (cur->letter == word[i]) {have = true; break;} else
                    cur = cur->left;
            }
            if (cur != NULL && cur->letter == word[i]) have = true;
            if (have) continue;
            cur->left = new tree;
            cur->left->next = cur->left->left = NULL;
            cur->left->letter = word[i];
            cur->left->words = 0;
            cur = cur->left;
        }

        //for (int i = 0; i < n; i ++)
        //    if (cur->next[word[i] - 'a'] != NULL) cur = cur->next[word[i] - 'a']; else
        //    {
        //        tree * nt = new tree;
        //        cur->next[word[i] - 'a'] = nt;
        //        cur = nt;
        //        for (int j = 0; j < 26; j ++) cur->next[j] = NULL;
        //        cur->words = 0;
        //    }
        cur->words ++;
    }
    void erase(char word[])
    {
        int n = strlen(word);
        tree * cur = T;
        //for (int i = 0; i < n; i ++)
        //    if (cur->next[word[i] - 'a'] != NULL) cur = cur->next[word[i] - 'a']; else return;
        cur->words --;
    }
    int count(char word[])
    {
        int n = strlen(word);
        tree * cur = T;
        for (int i = 0; i < n; i ++)
        {
            if (cur->next == NULL) return 0;
            cur = cur->next;

            bool have = false;
            while (cur->left != NULL)
            {
                if (cur->letter == word[i]) {have = true; break;} else
                    cur = cur->left;
            }
            if (cur != NULL && cur->letter == word[i]) have = true;
            if (!have) return 0;
        }
        //for (int i = 0; i < n; i ++)
        //    if (cur->next[word[i] - 'a'] != NULL) cur = cur->next[word[i] - 'a']; else return 0;
        return cur->words;
    }
};

int main()
{
    string_set A;
    int n;
    scanf("%d\n", &n);
    for (int i = 1; i <= n; i ++)
    {
        char s[50];
        gets(s);
        int c = A.count(s);
        if (c == 0)
            printf("OK\n"); else
            printf("%s%d\n", s, c);
        A.insert(s);
    }

    return 0;
}