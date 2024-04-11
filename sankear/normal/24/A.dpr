    program solution;

    {$APPTYPE CONSOLE}
    {$O-}

    uses
      SysUtils,
      Math;

    var
      n, i, a, b, c, ans, res : integer;
      used : array[1..100] of boolean;
      k : array[1..100] of integer;
      v, cost : array[1..100, 1..100] of integer;

    procedure dfs(x, y, z : integer);
    var i : integer;
    fl : boolean;
    begin
      used[x] := true;
      fl := false;
      if y <> 0 then begin
        fl := true;
        res := res + cost[x, y];
        dfs(v[x, y], 0, z);
      end
      else begin
        for i := 1 to k[x] do
          if not used[v[x, i]] then begin
            fl := true;
            res := res + cost[x, i];
            dfs(v[x, i], 0, z);
          end;
      end;
      if not fl then begin
        for i := 1 to k[x] do
          if v[x, i] = z then
            res := res + cost[x, i];
      end;
    end;

    begin
      //reset(input, 'input.txt');
      //rewrite(output, 'output.txt');
      read(n);
      for i := 1 to n do begin
        read(a, b, c);
        inc(k[a]);
        v[a, k[a]] := b;
        cost[a, k[a]] := 0;
        inc(k[b]);
        v[b, k[b]] := a;
        cost[b, k[b]] := c;
      end;
      ans := 2000000000;
      for i := 1 to n do begin
        res := 0;
        fillchar(used, sizeof(used), 0);
        dfs(i, 1, i);
        ans := min(ans, res);
        res := 0;
        fillchar(used, sizeof(used), 0);
        dfs(i, 2, i);
        ans := min(ans, res);
      end;
      write(ans);
    end.