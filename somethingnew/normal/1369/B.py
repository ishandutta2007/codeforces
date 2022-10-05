def solve():
    n = int(input())
    st = input()
    pref0 = 0
    for i in st:
        if i == "0":
            pref0 += 1
        else:
            break
    post1 = 0
    for i in st[::-1]:
        if i == "1":
            post1 += 1
        else:
            break
    if n != post1 + pref0:
        print(pref0 *"0"+"0"+post1*"1")
    else:
        print(pref0 * "0" + post1 * "1")
for i in range(int(input())):
    solve()