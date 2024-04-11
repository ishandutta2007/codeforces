import math

def prov(s):
    l = len(s)
    if l%2 != 0:
        return 'NO'
    else:
        s1 = s[0:l//2]
        s2 = s[l//2:]
        if s1 == s2:
            a = [0]
            for i in range(l//2):
                if s1[i] == s2[i]:
                    a.append(1)
                else:
                    a.append(0)
            if sum(a) == l//2:
                return 'YES'
            else:
                return 'NO'
        else:
            return 'NO'


n = int(input())
for i in range(n):
    s = input()
    print(prov(s))