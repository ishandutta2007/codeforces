def is_palindrome(S):
    a = S[::-1]
    return S == a


s = input()
if len(s) == 1:
    print('Impossible')
    exit(0)
hop = 0
if len(s) % 2:
    if len(set(s[:len(s)//2])) == 1:
        print('Impossible')
    else:
        print(2)
else:
    if len(set(s)) == 1:
        print('Impossible')
    else:
        if s[:len(s)//2] != s[len(s)//2:]:
            print(1)
        else:
            fl = 2
            while len(s)%2==0:
                s = s[:len(s)//2]
                if (len(s) % 2 == 0 and not is_palindrome(s[:len(s)//2])):
                    fl = 1
                    break
            print(fl)