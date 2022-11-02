#!/usr/bin/python

def main():
    n = int(raw_input())
    cur = []
    for i in range(n):
        s = raw_input()
        if s == "pwd":
            t = "/" + "/".join(cur)
            if t[-1] != '/': t = t + "/"
            print t
            continue                

        s = s[3:]
        if s[0] == '/': cur = []
        for x in s.split("/"):
            if len(x) > 0:
                cur.append(x)
        nc = []
        for x in cur:
            if x == "..":
                nc.pop()
            else:
                nc.append(x)
        cur = nc


if __name__ == "__main__":
    main()