def shift(s, start):
    return ''.join([chr(ord(c)+start) for c in s])

def ans(n, start):
    if n == 0:
        return ''
    if n == 1:
        return shift('a', start)
    elif n == 2:
        return shift('ab', start)
    elif n == 3:
        return shift('abc', start)
    elif n == 4:
        return shift('abaa', start)
    elif n == 6:
        return shift('bacada', start)
    elif n == 7:
        return shift('bacadae', start)
    elif n == 10:
        return shift('bacadaeafa', start)
    else:
        if n%3 == 0:
            sub = ans(n//3-2, start+2)
            return sub+shift('abb', start)+sub+shift('baa', start)+sub
        elif n%3 == 1:
            sub = ans(n//3-3, start+2)
            return sub+shift('aabbb', start)+sub+shift('bbaaa', start)+sub
        else:
            sub = ans(n//3, start+2)
            return sub+shift('a', start)+sub+shift('b', start)+sub

t = int(input())
for i in range(t):
    n = int(input())
    print(ans(n, 0))