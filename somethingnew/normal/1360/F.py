from math import sqrt
alph = [chr(i) for i in range(ord("a"), ord("z") + 1)]
def dif(st1,st2):
    d = 0
    for i in range(len(st1)):
        d += (st1[i] != st2[i])
    return d
def main():
    n, m = map(int,input().split())
    st = [list(input()) for i in range(n)]
    for i in range(m):
        src = [i for i in st[0]]
        for let in alph:
            src[i] = let
            tr = True
            for w in st:
                if dif(w, src) > 1:
                    tr = False
                    break
            if tr:
                print(''.join(src))
                return
    print(-1)
for t in range(int(input())):
    main()