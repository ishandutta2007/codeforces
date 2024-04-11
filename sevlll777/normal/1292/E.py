
import sys
n, L, minID = None, None, None
s = []

def fill(id, c):
    global n, L, s, minID
    L -= (s[id] == 'L')
    s = s[0:id] + c + s[ id +1:]
    minID = min(minID, id)

def query(cmd, str):
    global n, L, s, minID
    print(cmd, ''.join(str))
    print(cmd, ''.join(str), file=sys.stderr)
    sys.stdout.flush()
    if (cmd == '?'):
        result = list(map(int, input().split()))
        assert(result[0] != -1)
        for z in result[1:]:
            z -= 1
            for i in range(len(str)):
                assert(s[z+i] == 'L' or s[z+i] == str[ i ])
                fill(z+i, str[i])
    elif (cmd == '!'):
        correct = int(input())
        assert(correct == 1)

for _ in range(int(input())):
    n = int(input())
    if n >= 13:
        ans = [''] * (n + 1)
        print('? CO')
        co = list(map(int, input().split()))[1:]
        print('? CH')
        ch = list(map(int, input().split()))[1:]
        print('? CC')
        cc = list(map(int, input().split()))[1:]
        for d in co:
            ans[d] = 'C'
            ans[d + 1] = 'O'
        for d in ch:
            ans[d] = 'C'
            ans[d + 1] = 'H'
        for d in cc:
            ans[d] = 'C'
            ans[d + 1] = 'C'
        print('? OO')
        oo = list(map(int, input().split()))[1:]
        print('? OH')
        oh = list(map(int, input().split()))[1:]
        for d in oo:
            ans[d] = 'O'
            ans[d + 1] = 'O'
        for d in oh:
            ans[d] = 'O'
            ans[d + 1] = 'H'
        for i in range(1, n):
            if ans[i] == 'O' and ans[i + 1] == '':
                ans[i + 1] = 'C'
        for i in range(1, n):
            if ans[i] == '' and ans[i + 1] == 'O':
                ans[i] = 'H'
        for i in range(1, n):
            if ans[i] == '' and ans[i + 1] == 'H':
                ans[i] = 'H'
        for i in range(1, n):
            if ans[i] == '' and ans[i + 1] == '':
                ans[i] = 'H'
        print('? HOC')
        hoc = list(map(int, input().split()))[1:]
        for d in hoc:
            ans[d] = 'H'
            ans[d + 1] = 'O'
            ans[d + 2] = 'C'
        for d in range(2, n):
            if ans[d] == '':
                ans[d] = 'H'
        if ans[1] == '':
            print('?', 'H' + ''.join(ans[2:-1]))
            if input()[0] != '0':
                ans[1] = 'H'
            else:
                ans[1] = 'O'
        if ans[-1] == '':
            print('?', ''.join(ans[1:-1]) + 'H')
            if input()[0] != '0':
                ans[-1] = 'H'
            else:
                print('?', ''.join(ans[1:-1]) + 'O')
                if input()[0] != '0':
                    ans[-1] = 'O'
                else:
                    ans[-1] = 'C'
        print('!', ''.join(ans[1:]))
        kek = input()
    else:
        L, minID = n, n
        s = 'L' * n

        query('?', "CH")
        query('?', "CO")
        query('?', "HC")
        query('?', "HO")
        if (L == n):
            # the string exists in form O...OX...X, with X=C or X=H
            # or it's completely mono-character
            query('?', "CCC")
            if (minID < n):
                for x in range(minID - 1, -1, -1): fill(x, 'O')
            else:
                query('?', "HHH")
                if (minID < n):
                    for x in range(minID - 1, -1, -1): fill(x, 'O')
                else:
                    query('?', "OOO")
                    if (minID == n):
                        # obviously n=4
                        query('?', "OOCC")
                        if (minID == n):
                            fill(0, 'O')
                            fill(1, 'O')
                            fill(2, 'H')
                            fill(3, 'H')

                    if (s[n - 1] == 'L'):
                        t = s[0:n - 1] + 'C'
                        if (t[n - 2] == 'L'): t = t[0:n - 2] + 'C' + t[n - 1:]
                        query('?', t)
                        if (s[n - 1] == 'L'):
                            fill(n - 1, 'H')
                            if (s[n - 2] == 'L'): fill(n - 2, 'H')
        else:
            maxID = minID
            while (maxID < n - 1 and s[maxID + 1] != 'L'): maxID += 1
            for i in range(minID - 1, -1, -1):
                query('?', s[i + 1:i + 2] + s[minID:maxID + 1])
                if (minID != i):
                    for x in range(i + 1): fill(x, 'O')
                    break

            nextFilled = None
            i = maxID + 1
            while i < n:
                if (s[i] != 'L'):
                    i += 1
                    continue
                nextFilled = i
                while (nextFilled < n and s[nextFilled] == 'L'): nextFilled += 1
                query('?', s[0:i] + s[i - 1])
                if (s[i] == 'L'):
                    if (s[i - 1] != 'O'):
                        fill(i, 'O')
                    else:
                        if (nextFilled == n):
                            query('?', s[0:i] + 'C')
                            if (s[i] == 'L'): fill(i, 'H')
                            for x in range(i + 1, nextFilled): fill(x, s[i])
                        else:
                            for x in range(i, nextFilled): fill(x, s[nextFilled])
                        i = nextFilled - 1
                i += 1
        query('!', s)