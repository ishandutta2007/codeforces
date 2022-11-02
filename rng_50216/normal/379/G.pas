
const NN = 12345;
const INF = 15345;

var ans, ss, ff, pv, de, sz, he, ne : array[0 .. NN] of longint;
    was : array[0 .. NN] of boolean;
    dp : array[0 .. 4, 0 .. 2555, 0 .. 2555] of smallint;
    dd1, dd2 : array[0 .. 4, 0 .. 4, 0 .. 2555] of longint;
    d1, d2 : array[0 .. 4, 0 .. 2555] of longint;

procedure dfs(v, p, d : longint);
var e : longint;
  begin
    pv[v] := p;
    de[v] := d;
    e := he[v];
    while e >= 0 do begin
      if de[ff[e]] < 0 then begin
        dfs(ff[e], v, d + 1);
      end;
      e := ne[e];
    end;
  end;
  
function rev(mask : longint) : longint;
  begin
    rev := ((mask and 1) shl 1) or ((mask shr 1) and 1);
  end;
  
procedure dfs2(v : longint);
var e, cc, cc2, mask, mask1, mask2, cn, cn2, i, j, have, nhave, nmask, u, val1, val2, col : longint;
  begin
    e := he[v];
    sz[v] := 1;
    while e >= 0 do begin
      if de[ff[e]] > de[v] + 1 then begin
        u := ff[e];
        while u <> v do begin
          was[u] := true;
          u := pv[u];
        end;
        u := ff[e];
        while u <> v do begin
          dfs2(u);
          sz[v] += sz[u];
          u := pv[u];
        end;
      end;
      e := ne[e];
    end;
    e := he[v];
    while e >= 0 do begin
      if (de[ff[e]] > de[v]) and (not was[ff[e]]) then begin
        dfs2(ff[e]);
        sz[v] += sz[ff[e]];
      end;
      e := ne[e];
    end;
    e := he[v];
    cc := 0;
    for i := 0 to 3 do d1[i][0] := -INF;
    d1[0][0] := 0;
    while e >= 0 do begin
      if (de[ff[e]] > de[v]) and (not was[ff[e]]) then begin
        was[ff[e]] := true;
        for mask := 0 to 3 do
          for cn := 0 to cc + sz[ff[e]] do d2[mask][cn] := -INF;
        for col := 0 to 3 do 
          for cn := 0 to sz[ff[e]] do begin
            val1 := dp[col][ff[e]][cn];
            if (val1 = -INF) then continue;
            for have := 0 to cc do begin
              for mask := 0 to 3 do begin
                val2 := d1[mask][have];
                if (val2 = -INF) then continue;
                nmask := mask or col;
                nhave := have + cn;
                if (d2[nmask][nhave] < val1 + val2) then
                  d2[nmask][nhave] := val1 + val2;
              end;
            end;
          end;
        cc += sz[ff[e]];
        for mask := 0 to 3 do
          for cn := 0 to cc do
            d1[mask][cn] := d2[mask][cn]; 
      end;
      e := ne[e];
    end;
    e := he[v];
    while e >= 0 do begin
      if (de[ff[e]] > de[v] + 1) then begin
        u := ff[e];
        cc2 := sz[u];
        for i := 0 to 3 do
          for j := 0 to 3 do
            for cn := 0 to cc2 do
              dd1[i][j][cn] := -INF;
        for i := 0 to 3 do
          for cn := 0 to cc2 do
            dd1[i][i][cn] := dp[i][u][cn];
        u := pv[u];
        while u <> v do begin
          for i := 0 to 3 do
            for j := 0 to 3 do
              for cn := 0 to cc2 + sz[u] do 
                dd2[i][j][cn] := -INF;
          for i := 0 to 2 do
            for cn := 0 to sz[u] do begin
              val1 := dp[i][u][cn];
              if (val1 = -INF) then continue;
              for mask1 := 0 to 3 do
                for mask2 := 0 to 3 do if (mask2 and rev(i)) = 0 then
                  for cn2 := 0 to cc2 do begin
                    val2 := dd1[mask1][mask2][cn2];
                    if (val2 = -INF) then continue;
                    if dd2[mask1][i][cn + cn2] < val1 + val2 then
                      dd2[mask1][i][cn + cn2] := val1 + val2;
                  end;
            end;
          cc2 += sz[u];
          for i := 0 to 3 do
            for j := 0 to 3 do
              for cn := 0 to cc2 do
                dd1[i][j][cn] := dd2[i][j][cn];
          u := pv[u];
        end;
        for i := 0 to 3 do
          for cn := 0 to cc + cc2 do
            d2[i][cn] := -INF;
        for i := 0 to 3 do
          for j := 0 to 3 do
            for cn := 0 to cc2 do begin
              val1 := dd1[i][j][cn];
              if (val1 = -INF) then continue;
              for mask := 0 to 3 do begin
                for cn2 := 0 to cc do begin
                  val2 := d1[mask][cn2];
                  if val2 = -INF then continue;
                  if d2[mask or i or j][cn + cn2] < val1 + val2 then
                    d2[mask or i or j][cn + cn2] := val1 + val2;
                end;
              end;
            end;
        cc += cc2;
        for i := 0 to 3 do
          for cn := 0 to cc do
            d1[i][cn] := d2[i][cn];
      end;
      e := ne[e];
    end;
//    writeln(v, ' ', cc);
    for col := 0 to 3 do
      for cn := 0 to sz[v] do
        dp[col][v][cn] := -INF;
    for col := 0 to 2 do begin
      for mask := 0 to 3 do begin
        if (col and rev(mask)) <> 0 then continue;
        for cn := 0 to cc do begin
          val1 := d1[mask][cn];
          if val1 = -INF then continue;
          if col = 1 then begin
            if dp[col][v][cn + 1] < val1 then 
              dp[col][v][cn + 1] := val1;
          end else if col = 0 then begin
            if dp[col][v][cn] < val1 then
              dp[col][v][cn] := val1
          end else begin
            if dp[col][v][cn] < val1 + 1 then
              dp[col][v][cn] := val1 + 1;
          end;
        end;
      end;
    end;
//    for col := 0 to 2 do
//      for cn := 0 to sz[v] do begin
//        writeln(v, ' ', col, ' ', cn, ' ', dp[col][v][cn]);
//      end;
  end;
  
var cn, n, m, i : longint;

begin
  read(n, m);
  for i := 1 to m do begin
    read(ss[i], ff[i]);
    ss[i + m] := ff[i];
    ff[i + m] := ss[i];
  end;
  for i := 1 to n do he[i] := -1;
  for i := 1 to m + m do begin
    ne[i] := he[ss[i]];
    he[ss[i]] := i;
  end;
  for i := 1 to n do de[i] := -1;
  dfs(1, -1, 0);
  dfs2(1);
  for i := 0 to n do ans[i] := 0;
  for i := 0 to 3 do
    for cn := 0 to n do begin
      if ans[cn] < dp[i][1][cn] then
        ans[cn] := dp[i][1][cn];
    end;
  for i := 0 to n do begin
    if i > 0 then write(' ');
    write(ans[i]);
  end;
  writeln;
end.