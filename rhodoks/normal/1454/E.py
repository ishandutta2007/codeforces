import sys
import threading
from copy import deepcopy
import io,os
 
 
input = io.BytesIO(os.read(0, os.fstat(0).st_size)).readline
 
sys.setrecursionlimit(10**9)
threading.stack_size(16*2048*2048)
#threading.Thread(target=findloop).start()
#t = threading.Thread(target=main)
#t.start()
#t.join()
 
 
 
 
def getnum(index,neigh,visited):
    output = [0,0]
    endlist = []
    for ele in neigh[index]:
        if visited[ele]: continue
        visited[ele] = True
        [end,notend] =  getnum(ele,neigh,visited)
        endlist.append(end+1)     
        output[1] += notend+end
 
    endtot = sum(endlist)
    output[0] += endtot
    notend = 0
    for ele in endlist:
        notend += (endtot-ele)*ele 
    output[1] += notend//2
#    print(index,output)
    return output
    
 
def findloop(index,neigh,pre,visited,loop):
 
 
    if loop: return 
    if len(pre)>1 and index==pre[-2]: return
    if visited[index]:
        i = len(pre)-1
        while pre[i]!=index:
            loop.append(pre[i])
            i -= 1
        loop.append(index)
        return 
 
        
        
    
 
    pre.append(index)
    visited[index] = True
    for ele in neigh[index]:
        findloop(ele,neigh,pre,visited,loop)
        if loop: return 
 
    pre.pop()
    visited[index] = False
      
def main(n,neigh):
 
 
 
    loop = []
    visited = [False]*n
    findloop(0,neigh,[],visited,loop)
   
    
    visited = [False]*n
    for loopele in loop:
        visited[loopele] = True
 
    endlist = []
    notendlist = []
#    print(loop)    
    m = len(loop)
    for i in range(m):
        if len(neigh[loop[i]])==2: continue
 #       print(loop[i])
        [end,notend] = getnum(loop[i],neigh,visited)
        endlist.append(end)
        notendlist.append(notend)
 
    ans = 0
    ans += sum(notendlist)
    ans += m*(m-1)
    tot = sum(endlist)
    for ele in endlist:
        ans += ele*(2*m-1)
        ans += (tot-ele)*ele
 
    return ans
    
 
 
 
def solve():
    T = int(input())
    r = 1
    while r<=T:
        n = int(input())
        ans = 0
        neigh = [[] for i in range(n)]
        for i in range(n):
            p,q = map(int,input().split())
            neigh[p-1].append(q-1)
            neigh[q-1].append(p-1)
        ans = main(n,neigh)
        print(ans)
        r += 1
        
threading.Thread(target=solve).start()