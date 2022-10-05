def prowerka(stroka):
    if len(stroka) == 0:
        return True
    i = 0
    k = len(stroka) // 2
    while stroka[i] == stroka[-1-i]:
        if i >= k:
            return True
        i += 1
    return False
def pref(stroka):
    i = 0
    k = len(stroka) // 2
    while i < k and stroka[i] == stroka[-1-i]:
        i += 1
    newstroka = stroka[i:len(stroka)-i]
    ans1 = answ(newstroka)
    ans2 = answ(newstroka[::-1])[::-1]
    if len(ans1) > len(ans2):
        print(stroka[:i] + ans1 + stroka[len(stroka)-i:])
    else:
        print(stroka[:i] + ans2 + stroka[len(stroka)-i:])
def answ(stroka):
    gran = len(stroka) - 1
    while not prowerka(stroka[0:gran]):
        gran -= 1
    if gran != 0:
        return stroka[0:gran]
    else:
        return stroka[0]
for i in range(int(input())):
    st = input()
    pref(st)