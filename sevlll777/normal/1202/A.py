for _ in range(int(input())):
    s, t = input(), input()
    w = s[:t.rfind('1') + len(s) - len(t) + 1]
    print(len(w) - w.rfind('1') - 1)