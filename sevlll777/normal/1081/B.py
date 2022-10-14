def p(l):
    return n - l - 1


n = int(input())
mas = list(map(p, list(map(int, input().split()))))
ne = [0 for i in range(n)]
q = set(mas)
fl = 1
sh_color = 1
l = 1
t = 1
mop = 0
if fl:
    for elem in q:
        l = 1
        mop = 0
        for z in range(n):
            if mas[z] == elem and l <= (elem + 1):
                ne[z] = sh_color
                l += 1
                mop += 1
            elif l == elem + 2 and mas[z] == elem:
                sh_color += 1
                ne[z] = sh_color
                l = 2
                mop += 1
        if mop % (elem+1) != 0:
            print("Impossible")
            t = 0
            break
        sh_color += 1
if t:
    print("Possible")
    print(" ".join(list(map(str, ne))))